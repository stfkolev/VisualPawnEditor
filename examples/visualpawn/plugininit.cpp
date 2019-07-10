#include "plugininit.h"


 PluginInitData::PluginInitData() {
}




 PluginInitData::d_t &
PluginInitData::data( int i ) {
    return *std::next( data_.begin(), i );
}




 void
PluginInitData::addBack( const d_t &d ) {
    data_.emplace_back( d );
}




 void PluginInitData::remove( int i ) {
    const auto it = std::next( data_.cbegin(), i );
    data_.erase( it );
}
