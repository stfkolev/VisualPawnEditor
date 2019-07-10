#include "cvarmodel.h"


 CvarModel::CvarModel() :
    data_( new CvarData() ),
    lineEdit_( new QLineEdit() )
{
  lineEdit_->setMaximumSize( lineEdit_->sizeHint() );
  connect( lineEdit_, &QLineEdit::textChanged,
          this, &CvarModel::onTextEdited);
}




 CvarModel::~CvarModel() {
}




 unsigned int
CvarModel::nPorts( PortType portType ) const {

     switch ( portType ) {
        case PortType::In:
            return 0;

         case PortType::Out:
            return 1;
    }

     return 0;
}




 NodeDataType
CvarModel::dataType( PortType, PortIndex ) const {
    return CvarData().type();
}




 std::shared_ptr< NodeData >
CvarModel::outData( PortIndex ) {
    return data_;
}




 void
CvarModel::setInData( std::shared_ptr< NodeData >, PortIndex ) {
}




 QWidget *
CvarModel::embeddedWidget() {
    return lineEdit_;
}




 void
CvarModel::onTextEdited( const QString &s ) {

     data_.reset( new CvarData( s ) );
    constexpr PortIndex portIndex = 0;
    Q_EMIT dataUpdated( portIndex );
}
