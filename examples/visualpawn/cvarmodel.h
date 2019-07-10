#ifndef CVARMODEL_H
#define CVARMODEL_H
#pragma once

#include "cvardata.h"
#include <nodes/NodeData>
#include <nodes/NodeDataModel>
#include <memory>
#include <QLineEdit>
#include <QCoreApplication>


using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;
using QtNodes::PortIndex;
using QtNodes::PortType;


 class CvarModel : public NodeDataModel {
    Q_DECLARE_TR_FUNCTIONS( CvarModel )


 public:
    CvarModel();

     virtual ~CvarModel() override;


 public:
    QString caption() const override {
        return tr( "Cvar" );
    }

     bool captionVisible() const override {
        return true;
    }

     QString name() const override {
        return "Cvar";
    }

     unsigned int nPorts( PortType ) const override;

     NodeDataType dataType( PortType, PortIndex ) const override;

     ConnectionPolicy portOutConnectionPolicy( PortIndex ) const override {
      return ConnectionPolicy::One;
    }

     std::shared_ptr< NodeData > outData( PortIndex ) override;

     void setInData( std::shared_ptr< NodeData >, PortIndex ) override;

     QWidget *embeddedWidget() override;


 private Q_SLOTS:
  void onTextEdited( const QString & );


 private:
  std::shared_ptr< CvarData > data_;
  QLineEdit *lineEdit_;
};
#endif // CVARMODEL_H
