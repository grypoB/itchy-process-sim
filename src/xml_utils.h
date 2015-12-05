/*
 * xml_utils.h
 *
 *  Created on: 16 nov. 2015
 *      Author: vachoux
 */

#ifndef SRC_XML_UTILS_H_
#define SRC_XML_UTILS_H_

#include "tinyxml/tinyxml.h"

//! Check if element exists.
//! Throw an exception if element is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Attribute name.
 * \return	Pointer to element.
 */
TiXmlElement* check_elem (TiXmlElement* p_elem, const char* name) {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		throw string("Element '" + string(name) + "' missing");
	else return p_elem->FirstChildElement(name);
}

//! Extract an attribute value as a string.
//! Throw an exception if attribute is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Attribute name.
 * \param	mandatory	Is attribute mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Attribute string value from XML DOM or default value.
 */
std::string get_attr_str (TiXmlElement* p_elem,
                          const char* name,
                          bool mandatory = true,
                          std::string default_val = "") {
	using namespace std;
	if ( !p_elem->Attribute(name) )
		if ( mandatory ) throw string("Missing attribute '" + string(name) + "'");
		else return default_val;
	else return p_elem->Attribute(name);
}

//! Extract an attribute value as an int.
//! Throw an exception if attribute is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Attribute name.
 * \param	mandatory	Is attribute mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Attribute int value from XML DOM or default value.
 */
int get_attr_int (TiXmlElement* p_elem,
                  const char* name,
                  bool mandatory = true,
                  int default_val = 0) {
	using namespace std;
	int ival;
	switch ( p_elem->QueryIntAttribute(name, &ival) ) {
		case TIXML_SUCCESS :
			return ival;
			break;
		case TIXML_WRONG_TYPE :
			throw("Wrong attribute type for '" + string(name) + "'");
			break;
		case TIXML_NO_ATTRIBUTE :
			if ( mandatory )
				throw string("Missing attribute '" + string(name) + "'");
			else return default_val;
			break;
		default:
			break;
	}
	return -1;  // should never get there
}

//! Extract an attribute value as a double.
//! Throw an exception if attribute is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Attribute name.
 * \param	mandatory	Is attribute mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Attribute double value from XML DOM or default value.
 */
double get_attr_dbl (TiXmlElement* p_elem,
                     const char* name,
                     bool mandatory = true,
                     double default_val = 0) {
	using namespace std;
	double dval;
	switch ( p_elem->QueryDoubleAttribute(name, &dval) ) {
		case TIXML_SUCCESS :
			return dval;
			break;
		case TIXML_WRONG_TYPE :
			throw("Wrong attribute type for '" + string(name) + "'");
			break;
		case TIXML_NO_ATTRIBUTE :
			if ( mandatory )
				throw string("Missing attribute '" + string(name) + "'");
			else return default_val;
			break;
		default:
			break;
	}
	return -1;  // should never get there
}

std::string get_elem_val (TiXmlElement* p_elem,
                          const char* name,
                          bool mandatory = true,
                          std::string default_val = "") {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		if ( mandatory ) throw string("Missing element '" + string(name) + "'");
		else return default_val;
	else return p_elem->FirstChildElement(name)->GetText();
}

int get_elem_val (TiXmlElement* p_elem,
                          const char* name,
                          bool mandatory = true,
                          int default_val = 0) {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		if ( mandatory ) throw string("Missing element '" + string(name) + "'");
		else return default_val;
	else return atof(p_elem->FirstChildElement(name)->GetText());
}

//! Extract a string value from element.
//! Throw an exception if element is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Element name.
 * \param	mandatory	Is element mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Element value from XML DOM or default value.
 */
std::string get_elem_str (TiXmlElement* p_elem,
                          const char* name,
                          bool mandatory = true,
                          std::string default_val = "") {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		if ( mandatory ) throw string("Missing element '" + string(name) + "'");
		else return default_val;
	else return p_elem->FirstChildElement(name)->GetText();
}

//! Extract a double value from element.
//! Throw an exception if element is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Element name.
 * \param	mandatory	Is element mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Element value from XML DOM or default value.
 */
double get_elem_dbl (TiXmlElement* p_elem,
                     const char* name,
                     bool mandatory = true,
		               double default_val = 0) {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		if ( mandatory ) throw string("Missing element '" + string(name) + "'");
		else return default_val;
	else return atof(p_elem->FirstChildElement(name)->GetText());
}

//! Extract an integer value from element.
//! Throw an exception if element is missing.
/*!
 * \param	p_elem		Pointer to XML element.
 * \param	name		Element name.
 * \param	mandatory	Is element mandatory?
 * \param	default_val	If not, use the default value.
 * \return	Element value from XML DOM or default value.
 */
int get_elem_int (TiXmlElement* p_elem,
		            const char* name,
		            bool mandatory = true,
	               int default_val = 0) {
	using namespace std;
	if ( !p_elem->FirstChildElement(name) )
		if ( mandatory ) throw string("Missing element '" + string(name) + "'");
		else return default_val;
	else return atoi(p_elem->FirstChildElement(name)->GetText());
}

#endif /* SRC_XML_UTILS_H_ */
