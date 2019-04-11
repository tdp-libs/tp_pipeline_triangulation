#ifndef tp_pipeline_triangulation_ColorizePolygonsStepDelegate_h
#define tp_pipeline_triangulation_ColorizePolygonsStepDelegate_h

#include "tp_pipeline_triangulation/Globals.h"
#include "tp_pipeline/AbstractStepDelegate.h"

namespace tp_pipeline_triangulation
{

//##################################################################################################
class ColorizePolygonsStepDelegate: public tp_pipeline::AbstractStepDelegate
{
public:
  //################################################################################################
  ColorizePolygonsStepDelegate();

  //################################################################################################
  void executeStep(tp_pipeline::StepDetails* stepDetails,
                   const tp_pipeline::StepInput& inputs,
                   tp_data::Collection& output) const override;

  //################################################################################################
  void fixupParameters(tp_pipeline::StepDetails* stepDetails)const override;
};

}

#endif
