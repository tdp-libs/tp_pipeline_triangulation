#pragma once

#include "tp_utils/StringID.h"

#if defined(TP_PIPELINE_TRIANGULATION_LIBRARY)
#  define TP_PIPELINE_TRIANGULATION_SHARED_EXPORT TP_EXPORT
#else
#  define TP_PIPELINE_TRIANGULATION_SHARED_EXPORT TP_IMPORT
#endif
namespace tp_data
{
class CollectionFactory;
}

namespace tp_pipeline
{
class StepDelegateMap;
}

//##################################################################################################
//! Add functions that use polygon triangulation to the image processing pipeline.
namespace tp_pipeline_triangulation
{
TP_DECLARE_ID(             colorizePolygonsSID,                "Colorize polygons");

//##################################################################################################
//! Add the step delegates that this module provides to the StepDelegateMap
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates, const tp_data::CollectionFactory* collectionFactory);

//##################################################################################################
//! Static initialization of this module, see TP_STATIC_INIT in dependencies.pri
int staticInit();

}
