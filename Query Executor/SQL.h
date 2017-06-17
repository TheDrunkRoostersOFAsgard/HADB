//
// Created by gerardo on 15/06/17.
//

#ifndef SERVER_SQL_H
#define SERVER_SQL_H

#include <stdlib.h>
#include <string>

// include the sql parser
#include "SQLP/SQLParser.h"
#include "SQLP/sqlhelper.h"
#include <json/json.h>
using namespace std;
using  namespace hsql;

// contains printing utilities

int SQLP(string query) {

    SQLParserResult *result = SQLParser::parseSQLString(query);

    if (result->isValid()) {
        return 1;
    } else {
        return 0;
    }
}

#endif //SERVER_SQL_H
