#include "xml_parser.h"
#include "tinyxml/tinyxml.h"
#include "xml_utils.h"

using namespace std;

void xml_parser (string xml_file) {
	TiXmlDocument   dom(xml_file);  // DOM
	TiXmlElement*   p_root;       	// racine du DOM
	// Analyse du fichier XML et création du DOM

    if ( !dom.LoadFile() ) {
        throw "XML file '" + xml_file + "' cannot be analyzed. " + dom.ErrorDesc();
    }


	p_root = dom.FirstChildElement("bookstore");	// ou: p_root = doc.FirstChild()->ToElement();
	cout << "Racine: " << p_root->ValueStr() << endl;

	TiXmlElement* p_book = check_elem(p_root, "book");
	cout << "Category: " << get_attr_str(p_book, "category") << endl;

	std::string title = get_elem_str(p_book, "title");
	cout << "Title: " << title << endl;

	std::string author = get_elem_str(p_book, "author");
	cout << "Author: " << author << endl;

	int stock = get_attr_int(p_book, "stock");
	cout << "Stock: " << stock << endl;

	TiXmlElement* p_price = check_elem(p_book, "price");
	double price = get_elem_dbl(p_book, "price");
	std::string currency = get_attr_str(p_price, "currency");
	cout << "Price: " << price << " " << currency << endl;

}
