// Copyright 2016 Erwan MATHIEU <wawanbreton@gmail.com>
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

#ifndef BLURNODE_H
#define BLURNODE_H

#include "nodes/abstractnode.h"

class BlurNode : public AbstractNode
{
    Q_OBJECT

    public:
        explicit BlurNode(QObject *parent = NULL);

        virtual QList<cv::Mat> processImpl(const QList<cv::Mat> &inputs);

        const cv::Size getSize() const;

        const cv::Point &getAnchor() const;

    public slots:
        void setSize(const cv::Size &size);

        void setAnchor(const cv::Point &anchor);

    private:
        cv::Size _size;
        cv::Point _anchor;
};

#endif // BLURNODE_H
