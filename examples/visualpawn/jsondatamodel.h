#ifndef JSONDATAMODEL_H
#define JSONDATAMODEL_H
#pragma once

#include "jsondata.h"

class JsonDataModel : public NodeDataModel {
Q_OBJECT

public:

    ~JsonDataModel();

public:
    QString
    caption() const override {
        return QString("JSON Data");
    }

    QString
    name() const override {
        return QString("JSON Data");
    }

public:
    QJsonObject
    save() const override {
        QJsonObject modelJson;

        modelJson["name"] = name();

        return modelJson;
    }

public:
    unsigned int
    nPorts(PortType) const override {
        return 3;
    }

    NodeDataType
    dataType(PortType, PortIndex) const override {
        return JsonData().type();
    }

    std::shared_ptr<NodeData>
    outData(PortIndex) override {
        return std::make_shared<JsonData>();
    }

    void
    setInData(std::shared_ptr<NodeData>, int) override
      {
        //
      }

    QWidget *
    embeddedWidget() override { return nullptr; }
};

#endif // JSONDATAMODEL_H
