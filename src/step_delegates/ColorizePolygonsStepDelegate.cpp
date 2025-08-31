#include "tp_pipeline_triangulation/step_delegates/ColorizePolygonsStepDelegate.h"

#include "tp_image_utils_triangulation/DrawPolygons.h"

#include "tp_data_image_utils/members/ColorMapMember.h"

#include "tp_pipeline_image_utils/Globals.h"

#include "tp_data_math_utils/members/PolygonsMember.h"

#include "tp_pipeline/StepDetails.h"
#include "tp_pipeline/StepContext.h"

namespace tp_pipeline_triangulation
{

#define GROUPS    {tp_pipeline_image_utils::drawingSID()}
#define IN_PORTS  {{tp_pipeline_image_utils::colorImageSID(), tp_data_image_utils::colorMapSID()}, {tp_data_math_utils::polygonsSID(), tp_data_math_utils::polygonsSID()}}
#define OUT_PORTS {{tp_pipeline_image_utils::colorImageSID(), tp_data_image_utils::colorMapSID()}}

//##################################################################################################
ColorizePolygonsStepDelegate::ColorizePolygonsStepDelegate():
  tp_pipeline::StepDelegate(colorizePolygonsSID(), GROUPS, IN_PORTS, OUT_PORTS)
{

}

//##################################################################################################
void ColorizePolygonsStepDelegate::executeStep(tp_pipeline::StepContext* stepContext) const
{
  TP_UNUSED(stepContext);

  auto colorImage = stepContext->stepInput->memberCast<tp_data_image_utils::ColorMapMember>(tp_pipeline_image_utils::colorImageSID());
  if(!colorImage)
  {
    stepContext->stepOutput->addError("Faild to get source image.");
    return;
  }

  auto polygons = stepContext->stepInput->memberCast<tp_data_math_utils::PolygonsMember>(tp_data_math_utils::polygonsSID());
  if(!polygons)
  {
    stepContext->stepOutput->addError("Failed to find polygons.");
    return;
  }

  auto outMember = new tp_data_image_utils::ColorMapMember();
  if(stepContext->stepOutput->addMember(tp_pipeline_image_utils::colorImageSID(), std::shared_ptr<tp_data::AbstractMember>(outMember)))
  {
    for(size_t i=0; i<polygons->data.size(); i++)
      tp_image_utils_triangulation::drawPolygon(outMember->data,
                                                polygons->data.at(i).outer,
                                                tp_pipeline_image_utils::makeColor(i));
  };
}

//##################################################################################################
void ColorizePolygonsStepDelegate::fixupParameters(tp_pipeline::StepDetails* stepDetails) const
{
  std::vector<tp_utils::StringID> validParams;
  stepDetails->setParametersOrder(validParams);
  stepDetails->setValidParameters(validParams);
}

}
