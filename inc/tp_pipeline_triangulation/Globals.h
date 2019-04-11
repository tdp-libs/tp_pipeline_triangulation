#ifndef tp_pipeline_triangulation_Globals_h
#define tp_pipeline_triangulation_Globals_h

#include "tp_utils/StringID.h"

namespace tp_pipeline
{
class StepDelegateMap;
}

//##################################################################################################
//! Add functions that use polygon triangulation to the image processing pipeline.
namespace tp_pipeline_triangulation
{
TDP_DECLARE_ID(             colorizePolygonsSID,                "Colorize polygons")

//##################################################################################################
//! Add the step delegates that this module provides to the StepDelegateMap
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates);
}

#endif
