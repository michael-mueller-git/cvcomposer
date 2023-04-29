// Copyright 2022 Erwan MATHIEU <wawanbreton@gmail.com>
//
// This file is part of CvComposer.
//
// CvComposer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CvComposer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CvComposer.  If not, see <http://www.gnu.org/licenses/>.

#include "fillprocessor.h"

#include "global/cvutils.h"


FillProcessor::FillProcessor()
{
    addInput("size", PlugType::Size, QVariant::fromValue(cv::Size(10, 10)));
    addInput("color", PlugType::Color, QVariant::fromValue(cv::Scalar(255, 255, 255, 255)));

    addOutput("image", PlugType::Image);
}

Properties FillProcessor::processImpl(const Properties &inputs)
{
    Properties outputs;

    cv::Mat mat = cv::Mat(inputs["size"].value<cv::Size>(), CV_8UC3);
    mat.setTo(inputs["color"].value<cv::Scalar>());

    outputs.insert("image", QVariant::fromValue(mat));

    return outputs;
}

