#include "xml_parser.h"
#include "tinyxml/tinyxml.h"
#include "xml_utils.h"
#include <iostream>

#include "Server.h"
#include "State.h"
#include "Simulator.h"

#include "OnOffController.h"
#include "GainController.h"
#include "SaturationController.h"

#include "SinPhenomenon.h"
#include "RngPhenomenon.h"
#include "PulsePhenomenon.h"

using namespace std;

namespace {
    Phenomenon* parse_phen(TiXmlElement* pPhen, State *state) {
        Phenomenon* phen(NULL);
        string type;

        type = get_attr_str(pPhen, "type");
        if (type.compare("sin") == 0) {
            cout<< "Sin phenomenon ... ";
            phen = new SinPhenomenon(state,
                    get_elem_dbl(pPhen, "amplitude"),
                    get_elem_dbl(pPhen, "period"),
                    get_elem_dbl(pPhen, "offset",
                        false, SinPhen::DEFAULT_OFFSET),
                    get_elem_dbl(pPhen, "phase",
                        false, SinPhen::DEFAULT_PHASE));
        } else if (type.compare("pulse") == 0) {
            cout<< "Pulsed phenomenon ... ";
            phen = new PulsePhenomenon(state,
                    get_elem_dbl(pPhen, "low"),
                    get_elem_dbl(pPhen, "high"),
                    get_elem_dbl(pPhen, "p_width"),
                    get_elem_dbl(pPhen, "period"),
                    get_elem_dbl(pPhen, "rise",
                        false, PulsePhen::DEFAULT_RISE),
                    get_elem_dbl(pPhen, "fall",
                        false, PulsePhen::DEFAULT_FALL),
                    get_elem_dbl(pPhen, "delay",
                        false, PulsePhen::DEFAULT_DELAY));
        } else if (type.compare("random") == 0) {
            cout<< "Random phenomenon ... ";
            phen = new RngPhenomenon(state,
                    get_elem_dbl(pPhen, "min"),
                    get_elem_dbl(pPhen, "max"));
        }
        
        cout<< "OK" << endl;

        return phen;

    }

    Controller* parse_ctrl(TiXmlElement* pCtrl, State *state, Server *server) {
        Controller* ctrl(NULL);
        string type;

        type = get_attr_str(pCtrl, "type");

        if (type.compare("OnOff") == 0) {
            cout<< "OnOff controller ... ";
            ctrl = new OnOffController(state, server,
                    get_elem_dbl(pCtrl, "threshold_low"),
                    get_elem_dbl(pCtrl, "threshold_high"),
                    get_elem_dbl(pCtrl, "output_high"),
                    get_elem_dbl(pCtrl, "output_low"));
        } else if (type.compare("saturation") == 0) {
            cout<< "Saturation controller ... ";
            ctrl = new SaturationController(state, server,
                    get_elem_dbl(pCtrl, "val_sat"));
        } else if (type.compare("gain") == 0) {
            cout<< "Gain controller ... ";
            ctrl = new GainController(state, server,
                    get_elem_dbl(pCtrl, "val_ref"),
                    get_elem_dbl(pCtrl, "gain"));
        } else { // default type
            cout<< "Default (passif) controller ... ";
            ctrl = new Controller(state, server);
            
        }

        TiXmlElement* pLegend = check_elem(pCtrl, "legend");
        ctrl->set_legend_keys(get_elem_str(pLegend, "state"),
                get_elem_str(pLegend, "phen", false, ""),
                get_elem_str(pLegend, "ctrl", false, ""));

        cout<< "OK" << endl;
        return ctrl;
    }

    void parse_zone(TiXmlElement* pZone,
                    vector<State*> &state, vector<Phenomenon*> &phen,
                    vector<Controller*> &ctrl, Server *server) {
        TiXmlElement*   pCtrl;
        TiXmlElement*   pPhen;
        TiXmlElement*   pState;

        pCtrl = check_elem(pZone, "controller"); 
        pPhen = check_elem(pZone, "phenomenon"); 
        pState = check_elem(pZone, "state"); 

        //init state
        state.push_back(new State(get_elem_dbl(pState, "i_phen"),
                    get_elem_dbl(pState, "i_ctrl"),
                    get_elem_dbl(pState, "initial_value")));

        //init phen
        phen.push_back(parse_phen(pPhen, state[state.size()-1]));

        // init ctrl
        ctrl.push_back(parse_ctrl(pCtrl, state[state.size()-1], server));
    }
}

void xml_parser (string xml_file) {
	TiXmlDocument   dom(xml_file);  // DOM
	TiXmlElement*   pSim;
	TiXmlElement*   pZone;
	TiXmlElement*   pServer;
    
    vector<Controller*> ctrl;
    vector<Phenomenon*> phen;
    vector<State*> state;
    Server* server;
    Simulator sim;

    unsigned int zoneNB(0);
    string type("");



    if ( !dom.LoadFile() ) {
        throw "XML file '" + xml_file + "' cannot be analyzed. " + dom.ErrorDesc();
    }

    pSim = dom.FirstChildElement("sim");

    pServer = check_elem(pSim, "server");
    server = new Server(get_attr_str(pServer, "log",
                false, ServerConst::DEFAULT_NAME),
            get_attr_str(pServer, "conf",
                false, ServerConst::DEFAULT_GNUPLOT_CONF));

    pZone = check_elem(pSim, "zone");

    parse_zone(pZone, state, phen, ctrl, server);

    zoneNB++;

    for (unsigned int i=0; i<zoneNB ; i++) {
        sim.addAgent(*phen[i]);
        sim.addAgent(*ctrl[i]);
        sim.addAgent(*state[i]);
    }

    sim.addAgent(*server);

    sim.run( get_attr_dbl(pSim, "duration"), get_attr_int(pSim, "nbTicks"));
}

