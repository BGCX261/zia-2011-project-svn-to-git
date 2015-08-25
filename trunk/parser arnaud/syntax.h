#ifndef SYNTAX_H
#define SYNTAX_H
#include "header.h"
#include <boost/spirit.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/spirit.hpp>
#include <boost/spirit/core.hpp>
//#include <boost/spirit/include/classic_core.hpp>
using namespace std;
using namespace BOOST_SPIRIT_CLASSIC_NS;

struct Syntax:public grammar<Syntax>
{
    Syntax(header& target);
    template <typename ScannerT>
    struct definition
    {
        definition(Syntax const& self)
        {
			this->_request = this->_method >> ' ' >> this->_ressource >> ' ' >> this->_version >> '\n' >> this->_type >> " : " >> this->_acceptedtype >> eol_p;
            this->_method = (*graph_p)[assign_a(self.head.request.method)];
            this->_ressource = (*graph_p)[assign_a(self.head.request.ressource)];
            this->_version = (*graph_p)[assign_a(self.head.request.httpVersion)];//str_p("HTTP/");
			this->_type = (*graph_p)[assign_a(self.head.request.type)];
			this->_acceptedtype = (*graph_p)[assign_a(self.head.request.accepted_type)];
		}
        rule<ScannerT> const& start() const {return(_request);}
        rule<ScannerT> _request;
        rule<ScannerT> _method;
        rule<ScannerT> _ressource;
        rule<ScannerT> _version;
		rule<ScannerT> _type;
		rule<ScannerT> _acceptedtype;
    };
    header& head;
};

#endif // SYNTAX_H
