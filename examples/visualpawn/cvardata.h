#ifndef CVARDATA_H
#define CVARDATA_H
#pragma once

#include <nodes/NodeData>


using QtNodes::NodeData;
using QtNodes::NodeDataType;


class CvarData : public NodeData {
public:
   CvarData() : data_( "" ) {
   }

    explicit CvarData( const QString &s ) : data_( s ) {
   }

    NodeDataType type() const override {
       return NodeDataType{ "Cvar", "" };
   }

    const QString &data() const {
       return data_;
   }


private:
   QString data_;
};

#endif // CVARDATA_H
