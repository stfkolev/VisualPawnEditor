#ifndef BOOLDATAMODEL_H
#define BOOLDATAMODEL_H
#pragma once
#include "booldata.h"

#include <nodes/NodeData>
#include <nodes/NodeDataModel>
#include <memory>
#include <QCheckBox>
#include <QLineEdit>
#include <QCoreApplication>


using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;
using QtNodes::PortIndex;
using QtNodes::PortType;

class BoolDataModel : public NodeDataModel {
     Q_DECLARE_TR_FUNCTIONS( BoolDataMovel );

public:
    BoolDataModel();

    virtual
    ~BoolDataModel() override;

public:
    QString caption() const override {
        return tr( "Bool" );
    }

    bool captionVisible() const override {
        return true;
    }

    QString name() const override {
        return "Bool";
    }

    unsigned int nPorts( PortType ) const override;

    NodeDataType dataType ( PortType, PortIndex ) const override;

    ConnectionPolicy portOutConnectionPolicy( PortIndex ) const override {
     return ConnectionPolicy::One;
   }

    std::shared_ptr< NodeData > outData ( PortIndex ) override;

    void setInData ( std::shared_ptr < NodeData >, PortIndex ) override;

    QWidget *embeddedWidget() override;

private Q_SLOTS:
    void onStateChange( int );
    void onTextChange( const QString & );

private:
    std::shared_ptr< BoolData > data_;
    QCheckBox *checkBox_;
    QLineEdit *lineEdit_;

};

#endif // BOOLDATAMODEL_H
