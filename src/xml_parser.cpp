#include "xml_parser.h"
#include "tinyxml/tinyxml.h"
#include "xml_utils.h"
#include <iostream>

#include "OnOffController.h"
#include "Server.h"
#include "State.h"
#include "SinPhenomenon.h"
#include "Simulator.h"

using namespace std;

void xml_parser (string xml_file) {
	TiXmlDocument   dom(xml_file);  // DOM
	TiXmlElement*   pSim;
	TiXmlElement*   pZone;
	TiXmlElement*   pCtrl;
	TiXmlElement*   pPhen;
	TiXmlElement*   pState;
	TiXmlElement*   pServer;
	TiXmlElement*   pLegend;
    
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
    pCtrl = check_elem(pZone, "controller"); 
    pLegend = check_elem(pCtrl, "legend");
    pPhen = check_elem(pZone, "phenomenon"); 
    pState = check_elem(pZone, "state"); 

    cout << "still good" << endl;

    //init state
    state.push_back(new State(get_elem_dbl(pState, "i_phen"),
                              get_elem_dbl(pState, "i_ctrl"),
                              get_elem_dbl(pState, "initial_value")));

    
    cout << "still good" << endl;
    //init phen
    type = get_attr_str(pPhen, "type");
    if (type.compare("sin") == 0) {
        cout<< "Creating sin phen ..." << endl;
        phen.push_back(new SinPhenomenon(state[zoneNB],
                                get_elem_dbl(pPhen, "amplitude"),
                                get_elem_dbl(pPhen, "period"),
                                get_elem_dbl(pPhen, "offset",
                                             false, SinPhen::DEFAULT_OFFSET),
                                get_elem_dbl(pPhen, "phase",
                                             false, SinPhen::DEFAULT_PHASE)));
        cout<< "done" << endl;
    }

    // init ctrl
    type = get_attr_str(pCtrl, "type");
    if (type.compare("OnOff") == 0) {
        cout<< "Creating OnOff ctrl ..." << endl;
         ctrl.push_back(new OnOffController(state[zoneNB], server,
                                get_elem_dbl(pCtrl, "threshold_low"),
                                get_elem_dbl(pCtrl, "threshold_high"),
                                get_elem_dbl(pCtrl, "output_high"),
                                get_elem_dbl(pCtrl, "output_low")));
        cout<< "done" << endl;
    }
    ctrl[zoneNB]->set_legend_keys(get_elem_str(pLegend, "state"),
                             get_elem_str(pLegend, "phen", false, ""),
                             get_elem_str(pLegend, "ctrl", false, ""));
    zoneNB++;

    for (unsigned int i=0; i<zoneNB ; i++) {
        sim.addAgent(*phen[i]);
        sim.addAgent(*ctrl[i]);
        sim.addAgent(*state[i]);
    }

    sim.addAgent(*server);


    sim.run( get_attr_dbl(pSim, "duration"), get_attr_int(pSim, "nbTicks"));
}
