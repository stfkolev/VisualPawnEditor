#include <QtWidgets/QApplication>

#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/DataModelRegistry>
#include <nodes/ConnectionStyle>

#include "plugininitmodel.h"
#include "cvarmodel.h"
#include "models.hpp"
#include "jsondatamodel.h"
#include "booldatamodel.h"

using QtNodes::DataModelRegistry;
using QtNodes::FlowScene;
using QtNodes::FlowView;
using QtNodes::ConnectionStyle;

static std::shared_ptr<DataModelRegistry>
registerDataModels()
{
  auto ret = std::make_shared<DataModelRegistry>();

  ret->registerModel<NativeDataModel>();
  ret->registerModel<PluginInitModel>();
  ret->registerModel<CvarModel>();
  ret->registerModel<JsonDataModel>();
  ret->registerModel<BoolDataModel>();

  /*
     We could have more models registered.
     All of them become items in the context meny of the scene.

     ret->registerModel<AnotherDataModel>();
     ret->registerModel<OneMoreDataModel>();

   */

  return ret;
}


static
void
setStyle()
{
  ConnectionStyle::setConnectionStyle(
    R"(
  {
    "ConnectionStyle": {
      "UseDataDefinedColors": true
    }
  }
  )");
}


//------------------------------------------------------------------------------

int
main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  setStyle();

  FlowScene scene(registerDataModels());

  FlowView view(&scene);

  view.setWindowTitle("Pawn Visual editor");
  view.resize(800, 600);
  view.show();

  return app.exec();
}
