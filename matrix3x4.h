//
// Copyright (c) 2008-2017 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

struct xyz_t
{
    float x;
    float y;
    float z;

    friend xyz_t operator+(const xyz_t& a, const xyz_t& b)
    {
        return { a.x + b.x, a.y + b.y, a.z + b.z };
    }
    friend xyz_t operator-(const xyz_t& a, const xyz_t& b)
    {
        return { a.x - b.x, a.y - b.y, a.z - b.z };
    }

    explicit operator glm::vec3() const
    {
        return {x, y, z};
    }

    xyz_t xy0() const
    {
        return {x, y, 0};
    }
};

namespace Urho3D
{

/// 3x4 matrix for scene node transform calculations.
class Matrix3x4
{
public:
    /// Construct an identity matrix.
    Matrix3x4()
#ifndef URHO3D_SSE
       :m00_(1.0f),
        m01_(0.0f),
        m02_(0.0f),
        m03_(0.0f),
        m10_(0.0f),
        m11_(1.0f),
        m12_(0.0f),
        m13_(0.0f),
        m20_(0.0f),
        m21_(0.0f),
        m22_(1.0f),
        m23_(0.0f)
#endif
    {
#ifdef URHO3D_SSE
        _mm_storeu_ps(&m00_, _mm_set_ps(0.f, 0.f, 0.f, 1.f));
        _mm_storeu_ps(&m10_, _mm_set_ps(0.f, 0.f, 1.f, 0.f));
        _mm_storeu_ps(&m20_, _mm_set_ps(0.f, 1.f, 0.f, 0.f));
#endif
    }

    /// Copy-construct from another matrix.
    Matrix3x4(const Matrix3x4& matrix)
#if defined(URHO3D_SSE) && (!defined(_MSC_VER) || _MSC_VER >= 1700) /* Visual Studio 2012 and newer. VS2010 has a bug with these, see https://github.com/urho3d/Urho3D/issues/1044 */
    {
        _mm_storeu_ps(&m00_, _mm_loadu_ps(&matrix.m00_));
        _mm_storeu_ps(&m10_, _mm_loadu_ps(&matrix.m10_));
        _mm_storeu_ps(&m20_, _mm_loadu_ps(&matrix.m20_));
    }
#else
    :m00_(matrix.m00_),
     m01_(matrix.m01_),
     m02_(matrix.m02_),
     m03_(matrix.m03_),
     m10_(matrix.m10_),
     m11_(matrix.m11_),
     m12_(matrix.m12_),
     m13_(matrix.m13_),
     m20_(matrix.m20_),
     m21_(matrix.m21_),
     m22_(matrix.m22_),
     m23_(matrix.m23_)
    {
    }
#endif

    /// Construct from values.
    Matrix3x4(float v00, float v01, float v02, float v03,
              float v10, float v11, float v12, float v13,
              float v20, float v21, float v22, float v23) :
        m00_(v00),
        m01_(v01),
        m02_(v02),
        m03_(v03),
        m10_(v10),
        m11_(v11),
        m12_(v12),
        m13_(v13),
        m20_(v20),
        m21_(v21),
        m22_(v22),
        m23_(v23)
    {
    }

    /// Construct from a float array.
    explicit Matrix3x4(const float* data)
#ifndef URHO3D_SSE
       :m00_(data[0]),
        m01_(data[1]),
        m02_(data[2]),
        m03_(data[3]),
        m10_(data[4]),
        m11_(data[5]),
        m12_(data[6]),
        m13_(data[7]),
        m20_(data[8]),
        m21_(data[9]),
        m22_(data[10]),
        m23_(data[11])
#endif
    {
#ifdef URHO3D_SSE
        _mm_storeu_ps(&m00_, _mm_loadu_ps(data));
        _mm_storeu_ps(&m10_, _mm_loadu_ps(data + 4));
        _mm_storeu_ps(&m20_, _mm_loadu_ps(data + 8));
#endif
    }

    /// Assign from another matrix.
    Matrix3x4& operator =(const Matrix3x4& rhs)
    {
#if defined(URHO3D_SSE) && (!defined(_MSC_VER) || _MSC_VER >= 1700) /* Visual Studio 2012 and newer. VS2010 has a bug with these, see https://github.com/urho3d/Urho3D/issues/1044 */
        _mm_storeu_ps(&m00_, _mm_loadu_ps(&rhs.m00_));
        _mm_storeu_ps(&m10_, _mm_loadu_ps(&rhs.m10_));
        _mm_storeu_ps(&m20_, _mm_loadu_ps(&rhs.m20_));
#else
        m00_ = rhs.m00_;
        m01_ = rhs.m01_;
        m02_ = rhs.m02_;
        m03_ = rhs.m03_;
        m10_ = rhs.m10_;
        m11_ = rhs.m11_;
        m12_ = rhs.m12_;
        m13_ = rhs.m13_;
        m20_ = rhs.m20_;
        m21_ = rhs.m21_;
        m22_ = rhs.m22_;
        m23_ = rhs.m23_;
#endif
        return *this;
    }

    /// Test for equality with another matrix without epsilon.
    bool operator ==(const Matrix3x4& rhs) const
    {
#ifdef URHO3D_SSE
        __m128 c0 = _mm_cmpeq_ps(_mm_loadu_ps(&m00_), _mm_loadu_ps(&rhs.m00_));
        __m128 c1 = _mm_cmpeq_ps(_mm_loadu_ps(&m10_), _mm_loadu_ps(&rhs.m10_));
        c0 = _mm_and_ps(c0, c1);
        __m128 c2 = _mm_cmpeq_ps(_mm_loadu_ps(&m20_), _mm_loadu_ps(&rhs.m20_));
        c0 = _mm_and_ps(c0, c2);
        __m128 hi = _mm_movehl_ps(c0, c0);
        c0 = _mm_and_ps(c0, hi);
        hi = _mm_shuffle_ps(c0, c0, _MM_SHUFFLE(1, 1, 1, 1));
        c0 = _mm_and_ps(c0, hi);
        return _mm_cvtsi128_si32(_mm_castps_si128(c0)) == -1;
#else
        const float* leftData = Data();
        const float* rightData = rhs.Data();

        for (unsigned i = 0; i < 12; ++i)
        {
            if (leftData[i] != rightData[i])
                return false;
        }

        return true;
#endif
    }

    /// Test for inequality with another matrix without epsilon.
    bool operator !=(const Matrix3x4& rhs) const { return !(*this == rhs); }

    /// Add a matrix.
    Matrix3x4 operator +(const Matrix3x4& rhs) const
    {
#ifdef URHO3D_SSE
        Matrix3x4 ret;
        _mm_storeu_ps(&ret.m00_, _mm_add_ps(_mm_loadu_ps(&m00_), _mm_loadu_ps(&rhs.m00_)));
        _mm_storeu_ps(&ret.m10_, _mm_add_ps(_mm_loadu_ps(&m10_), _mm_loadu_ps(&rhs.m10_)));
        _mm_storeu_ps(&ret.m20_, _mm_add_ps(_mm_loadu_ps(&m20_), _mm_loadu_ps(&rhs.m20_)));
        return ret;
#else
        return Matrix3x4(
            m00_ + rhs.m00_,
            m01_ + rhs.m01_,
            m02_ + rhs.m02_,
            m03_ + rhs.m03_,
            m10_ + rhs.m10_,
            m11_ + rhs.m11_,
            m12_ + rhs.m12_,
            m13_ + rhs.m13_,
            m20_ + rhs.m20_,
            m21_ + rhs.m21_,
            m22_ + rhs.m22_,
            m23_ + rhs.m23_
        );
#endif
    }

    /// Subtract a matrix.
    Matrix3x4 operator -(const Matrix3x4& rhs) const
    {
#ifdef URHO3D_SSE
        Matrix3x4 ret;
        _mm_storeu_ps(&ret.m00_, _mm_sub_ps(_mm_loadu_ps(&m00_), _mm_loadu_ps(&rhs.m00_)));
        _mm_storeu_ps(&ret.m10_, _mm_sub_ps(_mm_loadu_ps(&m10_), _mm_loadu_ps(&rhs.m10_)));
        _mm_storeu_ps(&ret.m20_, _mm_sub_ps(_mm_loadu_ps(&m20_), _mm_loadu_ps(&rhs.m20_)));
        return ret;
#else
        return Matrix3x4(
            m00_ - rhs.m00_,
            m01_ - rhs.m01_,
            m02_ - rhs.m02_,
            m03_ - rhs.m03_,
            m10_ - rhs.m10_,
            m11_ - rhs.m11_,
            m12_ - rhs.m12_,
            m13_ - rhs.m13_,
            m20_ - rhs.m20_,
            m21_ - rhs.m21_,
            m22_ - rhs.m22_,
            m23_ - rhs.m23_
        );
#endif
    }

    /// Multiply with a scalar.
    Matrix3x4 operator *(float rhs) const
    {
#ifdef URHO3D_SSE
        Matrix3x4 ret;
        const __m128 mul = _mm_set1_ps(rhs);
        _mm_storeu_ps(&ret.m00_, _mm_mul_ps(_mm_loadu_ps(&m00_), mul));
        _mm_storeu_ps(&ret.m10_, _mm_mul_ps(_mm_loadu_ps(&m10_), mul));
        _mm_storeu_ps(&ret.m20_, _mm_mul_ps(_mm_loadu_ps(&m20_), mul));
        return ret;
#else
        return Matrix3x4(
            m00_ * rhs,
            m01_ * rhs,
            m02_ * rhs,
            m03_ * rhs,
            m10_ * rhs,
            m11_ * rhs,
            m12_ * rhs,
            m13_ * rhs,
            m20_ * rhs,
            m21_ * rhs,
            m22_ * rhs,
            m23_ * rhs
        );
#endif
    }

    /// Multiply a matrix.
    Matrix3x4 operator *(const Matrix3x4& rhs) const
    {
        return Matrix3x4(
            m00_ * rhs.m00_ + m01_ * rhs.m10_ + m02_ * rhs.m20_,
            m00_ * rhs.m01_ + m01_ * rhs.m11_ + m02_ * rhs.m21_,
            m00_ * rhs.m02_ + m01_ * rhs.m12_ + m02_ * rhs.m22_,
            m00_ * rhs.m03_ + m01_ * rhs.m13_ + m02_ * rhs.m23_ + m03_,
            m10_ * rhs.m00_ + m11_ * rhs.m10_ + m12_ * rhs.m20_,
            m10_ * rhs.m01_ + m11_ * rhs.m11_ + m12_ * rhs.m21_,
            m10_ * rhs.m02_ + m11_ * rhs.m12_ + m12_ * rhs.m22_,
            m10_ * rhs.m03_ + m11_ * rhs.m13_ + m12_ * rhs.m23_ + m13_,
            m20_ * rhs.m00_ + m21_ * rhs.m10_ + m22_ * rhs.m20_,
            m20_ * rhs.m01_ + m21_ * rhs.m11_ + m22_ * rhs.m21_,
            m20_ * rhs.m02_ + m21_ * rhs.m12_ + m22_ * rhs.m22_,
            m20_ * rhs.m03_ + m21_ * rhs.m13_ + m22_ * rhs.m23_ + m23_
        );
    }
    /// Set uniform scaling elements.
    void SetScale(float scale)
    {
        m00_ = scale;
        m11_ = scale;
        m22_ = scale;
    }

    /// Return float data.
    const float* Data() const { return &m00_; }

    /// Return matrix element.
    float Element(unsigned i, unsigned j) const { return Data()[i * 4 + j]; }

    float m00_;
    float m01_;
    float m02_;
    float m03_;

    float m10_;
    float m11_;
    float m12_;
    float m13_;

    float m20_;
    float m21_;
    float m22_;
    float m23_;

    float m30_;
    float m31_;
    float m32_;
    float m33_;

    float yaw() const
    {
        return (atan2(m01_, m00_) * 180.f) / 3.14f;
    }

    float pitch() const
    {
        return (atan2(-m12_, m22_) * 180.f) / 3.14f;
    }

    xyz_t forward_vector() const { return xyz_t(m13_, m23_, m33_); }
};

/// Multiply a 3x4 matrix with a scalar.
inline Matrix3x4 operator *(float lhs, const Matrix3x4& rhs) { return rhs * lhs; }

}
