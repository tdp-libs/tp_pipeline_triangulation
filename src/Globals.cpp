#include "tp_pipeline_triangulation/Globals.h"
#include "tp_pipeline_triangulation/step_delegates/ColorizePolygonsStepDelegate.h"

#include "tp_pipeline/StepDelegateMap.h"

//##################################################################################################
namespace tp_pipeline_triangulation
{
TDP_DEFINE_ID(             colorizePolygonsSID,                "Colorize polygons")

//##################################################################################################
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates)
{
  stepDelegates.addStepDelegate(new ColorizePolygonsStepDelegate);
}
}
