#ifndef BOOLDATA_H
#define BOOLDATA_H
#pragma once

#include <nodes/NodeData>



using QtNodes::NodeData;
using QtNodes::NodeDataType;

class BoolData : public NodeData {
public:

    BoolData() : data_(false)
    {};

    explicit BoolData(bool data_, QString text_) :
        data_(data_), text_(text_)
    {};

    explicit
    BoolData(bool data_) : data_(data_)
    {};

    explicit
    BoolData(QString text_) : text_(text_)
    {};

    NodeDataType type() const override {
       return NodeDataType{ "Bool", "Bool" };
   }

    const bool &data() const {
       return data_;
   }

private:

bool data_;
QString text_;

};

#endif // BOOLDATA_H
