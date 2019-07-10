#ifndef PLUGININIT_H
#define PLUGININIT_H
#pragma once

#include <nodes/NodeData>
#include <QCoreApplication>


using QtNodes::NodeData;
using QtNodes::NodeDataType;


class PluginInitData : public NodeData {
   Q_DECLARE_TR_FUNCTIONS( PluginInitData )

    typedef QString d_t;
   typedef std::vector< d_t > data_t;


public:
   PluginInitData();

    NodeDataType type() const override {
       const QString name = tr( "PluginInit" );
       return NodeDataType{ "PluginInit", name };
   }

    const data_t &data() const {
       return data_;
   }

    d_t &data( int i );

    void addBack( const d_t & );

    void remove( int i );


private:
   data_t data_;
};

#endif // PLUGINLIST_H
