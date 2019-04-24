#include "tp_pipeline_triangulation/Globals.h"
#include "tp_pipeline_triangulation/step_delegates/ColorizePolygonsStepDelegate.h"

#include "tp_pipeline/StepDelegateMap.h"

//##################################################################################################
namespace tp_pipeline_triangulation
{
TDP_DEFINE_ID(             colorizePolygonsSID,                "Colorize polygons")

//##################################################################################################
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates, const tp_data::CollectionFactory* collectionFactory)
{
  TP_UNUSED(collectionFactory);
  stepDelegates.addStepDelegate(new ColorizePolygonsStepDelegate);
}

REGISTER_CREATE_STEP_DELEGATES;

//##################################################################################################
int staticInit()
{
  return 0;
}

}
