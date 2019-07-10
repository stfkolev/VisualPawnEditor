#ifndef JSONDATA_H
#define JSONDATA_H
#pragma once

#include <QtCore/QObject>

#include <nodes/NodeData>
#include <nodes/NodeDataModel>

#include <memory>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class JsonData : public NodeData{
public:

  NodeDataType
  type() const override
  {
      return NodeDataType {"JSON", "JSON"};
  }
};

#endif // JSONDATA_H
