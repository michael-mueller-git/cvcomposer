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

#include "numberpairprocessor.h"

#include "global/cvutils.h"


NumberPairProcessor::NumberPairProcessor()
{
    addInput("x", PlugType::Double);
    addInput("y", PlugType::Double);

    addOutput("pair", PlugType::Size | PlugType::Point);
}

class 

Properties NumberPairProcessor::processImpl(const Properties &inputs)
{
    Properties outputs;

    // cv::Size size = cv::Size(
    //     (int)inputs["x"].toInt(),
    //     (int)inputs["y"].toInt()
    // );

    // outputs.insert("size", QVariant::fromValue(size));

    cv::Point point = cv::Point(
        (int)inputs["x"].toInt(),
        (int)inputs["y"].toInt()
    );

    outputs.insert("pair", QVariant::fromValue(point));

    return outputs;
}

