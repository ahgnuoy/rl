//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef RL_SG_ODE_SHAPE_H
#define RL_SG_ODE_SHAPE_H

#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/VRMLnodes/SoVRMLShape.h>
#include <ode/ode.h>

#include "../Shape.h"

namespace rl
{
	namespace sg
	{
		namespace ode
		{
			class RL_SG_EXPORT Shape : public ::rl::sg::Shape
			{
			public:
				EIGEN_MAKE_ALIGNED_OPERATOR_NEW
				
				Shape(::SoVRMLShape* shape, Body* body);
				
				virtual ~Shape();
				
				using ::rl::sg::Shape::getTransform;
				
				::rl::math::Transform getTransform() const;
				
				void setTransform(const ::rl::math::Transform& transform);
				
				::dGeomID geom;
				
			protected:
				
			private:
				static void triangleCallback(void* userData, ::SoCallbackAction* action, const ::SoPrimitiveVertex* v1, const ::SoPrimitiveVertex* v2, const ::SoPrimitiveVertex* v3);
				
				::rl::math::Transform baseTransform;
				
				::dTriMeshDataID data;
				
				::std::vector<::dTriIndex> indices;
				
				::rl::math::Transform transform;
				
				::std::vector<::dReal> vertices;
			};
		}
	}
}

#endif // RL_SG_ODE_SHAPE_H
