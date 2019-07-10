#include "plugininitmodel.h"
#include "cvardata.h"


 PluginInitModel::PluginInitModel() :
    data_( new PluginInitData )
{
    data_->addBack( "" );
}




 PluginInitModel::~PluginInitModel() {
}




 unsigned int
PluginInitModel::nPorts( PortType portType ) const {

     switch ( portType ) {
        case PortType::In:
            return data_->data().size();

         case PortType::Out:
            return 1;
    }

     return 0;
}




 QString
PluginInitModel::portCaption( PortType portType, PortIndex portIndex ) const {

     if ( portType == PortType::In ) {
        const QString text = data_->data( portIndex );
        //const QString type = CvarData().type().name;
        return CvarData().data() + " " + text;
    }

     return "";
}




 NodeDataType
PluginInitModel::dataType( PortType portType, PortIndex ) const {

     switch ( portType ) {
        case PortType::In:
            return CvarData().type();

         case PortType::Out:
            return PluginInitData().type();
    }

     return CvarData().type();
}




 std::shared_ptr< NodeData >
PluginInitModel::outData( PortIndex ) {
    return data_;
}




 void
PluginInitModel::setInData( std::shared_ptr< NodeData > nd, PortIndex portIndex ) {

     const auto v = std::dynamic_pointer_cast< CvarData >( nd );
    if ( !v ) {
        // data removed (disconnected)
        // \todo Fix the problems when reassign connections. Not good.
        if ( portIndex < data_->data().size() ) {
            data_->remove( portIndex );
            Q_EMIT portRemoved();
        }
        return;
    }

     // data added (connected)
    data_->data( portIndex ) = v->data();

     // always add one more river when last input port connected
    if ( portIndex == (data_->data().size() - 1) ) {
        data_->addBack( "" );
        emit portAdded();
    }
}




 QWidget *
PluginInitModel::embeddedWidget() {
    return nullptr;
}
