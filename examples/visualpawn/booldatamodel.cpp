#include "booldatamodel.h"

BoolDataModel::BoolDataModel() :
    data_ (new BoolData() ),
    checkBox_( new QCheckBox() ),
    lineEdit_(new QLineEdit() )
{
    checkBox_->setMaximumSize(checkBox_->sizeHint());
    lineEdit_->setMaximumSize(lineEdit_->sizeHint());
    connect(lineEdit_, &QLineEdit::textEdited, this, &BoolDataModel::onTextChange);
    connect(checkBox_, &QCheckBox::stateChanged, this, &BoolDataModel::onStateChange);
}

BoolDataModel::~BoolDataModel() {

}

unsigned int
BoolDataModel::nPorts (PortType portType ) const {
    switch(portType) {
        case PortType::In:
            return 0;
        case PortType::Out:
            return 1;
    }

    return 0;
}

NodeDataType
BoolDataModel::dataType(PortType, PortIndex) const {
    return BoolData().type();
}

std::shared_ptr< NodeData >
BoolDataModel::outData(PortIndex) {
    return data_;
}

void BoolDataModel::setInData( std::shared_ptr< NodeData >, PortIndex ) {

}

QWidget *
BoolDataModel::embeddedWidget() {
    return checkBox_;
}

void
BoolDataModel::onStateChange( int checked) {
    data_.reset( new BoolData(checked) );

    constexpr PortIndex portIndex = 0;
    Q_EMIT dataUpdated( portIndex );
}


void BoolDataModel::onTextChange( const QString &s ) {
    data_.reset(new BoolData(s));

    constexpr PortIndex portIndex = 0;
    Q_EMIT dataUpdated( portIndex );
}
