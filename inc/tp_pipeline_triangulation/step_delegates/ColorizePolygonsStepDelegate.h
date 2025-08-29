#pragma once

#include "tp_pipeline_triangulation/Globals.h"

#include "tp_pipeline/StepDelegate.h"

namespace tp_pipeline_triangulation
{

//##################################################################################################
class TP_PIPELINE_TRIANGULATION_SHARED_EXPORT ColorizePolygonsStepDelegate: public tp_pipeline::StepDelegate
{
public:
  //################################################################################################
  ColorizePolygonsStepDelegate();

  //################################################################################################
  void executeStep(tp_pipeline::StepContext* stepContext) const override;

  //################################################################################################
  void fixupParameters(tp_pipeline::StepDetails* stepDetails)const override;
};

}
