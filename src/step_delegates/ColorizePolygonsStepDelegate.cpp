#include "tp_pipeline_triangulation/step_delegates/ColorizePolygonsStepDelegate.h"

#include "tp_image_utils_triangulation/DrawPolygons.h"

#include "tp_data_image_utils/members/ColorMapMember.h"

#include "tp_pipeline_image_utils/Globals.h"

#include "tp_data_math_utils/members/PolygonsMember.h"

#include "tp_pipeline/StepDetails.h"
#include "tp_pipeline/StepInput.h"

#include "tp_data/Collection.h"

namespace tp_pipeline_triangulation
{

//##################################################################################################
ColorizePolygonsStepDelegate::ColorizePolygonsStepDelegate():
  tp_pipeline::AbstractStepDelegate(colorizePolygonsSID(), {tp_pipeline_image_utils::drawingSID()})
{

}

//##################################################################################################
void ColorizePolygonsStepDelegate::executeStep(tp_pipeline::StepDetails* stepDetails,
                                               const tp_pipeline::StepInput& input,
                                               tp_data::Collection& output) const
{
  std::string colorImageName = stepDetails->parameterValue<std::string>(tp_pipeline_image_utils::colorImageSID());
  std::string   polygonsName = stepDetails->parameterValue<std::string>(   tp_data_math_utils::polygonsSID());

  const tp_data_image_utils::ColorMapMember* colorImage{nullptr};
  input.memberCast(colorImageName, colorImage);

  if(!colorImage)
  {
    output.addError("Failed to find color image.");
    return;
  }

  auto outMember = new tp_data_image_utils::ColorMapMember(stepDetails->lookupOutputName("Output image"));
  outMember->data = colorImage->data;
  size_t ii=0;

  auto addPolygons = [&](const std::vector<tp_math_utils::Polygon>& polygons)
  {
    for(size_t i=0; i<polygons.size(); i++, ii++)
      tp_image_utils_triangulation::drawPolygon(outMember->data,
                                                polygons.at(i).outer,
                                                tp_pipeline_image_utils::makeColor(ii));
  };

  if(polygonsName.empty())
  {
    if(input.previousSteps.empty())
    {
      output.addError("No input data found.");
      return;
    }

    for(auto member : input.previousSteps.back()->members())
    {
      auto polygons = dynamic_cast<tp_data_math_utils::PolygonsMember*>(member);
      if(polygons)
        addPolygons(polygons->data);
    }
  }
  else
  {
    tp_data_math_utils::PolygonsMember* polygons{nullptr};
    input.memberCast(polygonsName, polygons);

    if(!polygons)
    {
      output.addError("Failed to find polygons.");
      return;
    }

    addPolygons(polygons->data);
  }
}

//##################################################################################################
void ColorizePolygonsStepDelegate::fixupParameters(tp_pipeline::StepDetails* stepDetails) const
{
  stepDetails->setOutputNames({"Output image"});

  std::vector<tp_utils::StringID> validParams;
  const std::unordered_map<tp_utils::StringID, tp_pipeline::Parameter>& parameters = stepDetails->parameters();

  {
    const tp_utils::StringID& name = tp_pipeline_image_utils::colorImageSID();
    tp_pipeline::Parameter param = tpGetMapValue(parameters, name);
    param.name = name;
    param.description = "The source color image to draw on.";
    param.type = tp_pipeline::namedDataSID();

    stepDetails->setParamerter(param);
    validParams.push_back(name);
  }

  {
    const tp_utils::StringID& name = tp_data_math_utils::polygonsSID();
    tp_pipeline::Parameter param = tpGetMapValue(parameters, name);
    param.name = name;
    param.description = "The polygons to draw.";
    param.type = tp_pipeline::namedDataSID();

    stepDetails->setParamerter(param);
    validParams.push_back(name);
  }

  stepDetails->setParametersOrder(validParams);
  stepDetails->setValidParameters(validParams);
}

}
