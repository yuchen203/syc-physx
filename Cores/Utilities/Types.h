#pragma once

#include <Eigen/Dense>
#include <Eigen/Sparse>

#include <cstddef>

namespace PhysX {

#define DECLARE_EIGEN_VECTOR_TYPES(type, t)							\
using	Vector2##t			=	Eigen::Vector2##t;					\
using	Vector3##t			=	Eigen::Vector3##t;					\
using	Vector4##t			=	Eigen::Vector4##t;					\
using	VectorX##t			=	Eigen::VectorX##t;

#define DECLARE_EIGEN_MATRIX_TYPES(type, t)							\
using	Matrix2##t			=	Eigen::Matrix2##t;					\
using	Matrix3##t			=	Eigen::Matrix3##t;					\
using	Matrix4##t			=	Eigen::Matrix4##t;					\
using	Triplet##t			=	Eigen::Triplet<type>;				\
using	SparseMatrix##t		=	Eigen::SparseMatrix<type>;

DECLARE_EIGEN_VECTOR_TYPES(int, i)
DECLARE_EIGEN_VECTOR_TYPES(float, f)
DECLARE_EIGEN_VECTOR_TYPES(double, d)

DECLARE_EIGEN_MATRIX_TYPES(float, f)
DECLARE_EIGEN_MATRIX_TYPES(double, d)

#undef DECLARE_EIGEN_VECTOR_TYPES
#undef DECLARE_EIGEN_MATRIX_TYPES

#define DECLARE_REAL_TYPES(type, t)									\
using	real				=	type;								\
using	Vector2r			=	Vector2##t;							\
using	Vector3r			=	Vector3##t;							\
using	Vector4r			=	Vector4##t;							\
using	VectorXr			=	VectorX##t;							\
using	Matrix2r			=	Matrix2##t;							\
using	Matrix3r			=	Matrix3##t;							\
using	Matrix4r			=	Matrix4##t;							\
using	Tripletr			=	Triplet##t;							\
using	SparseMatrixr		=	SparseMatrix##t;

#ifdef USE_FLOAT
DECLARE_REAL_TYPES(float, f)
#else
DECLARE_REAL_TYPES(double, d)
#endif

#undef DECLARE_REAL_TYPES

template <int Dim, typename Scalar> using Vector = Eigen::Matrix<Scalar, Dim, 1>;
template <int Dim, typename Scalar> using Matrix = Eigen::Matrix<Scalar, Dim, Dim>;

#define DECLARE_DIM_TYPES(Dim)										\
static_assert(2 <= Dim && Dim <= 3, "Dimension must be 2 or 3.");	\
using	VectorDr			=	Vector<Dim, real>;					\
using	VectorDf			=	Vector<Dim, float>;					\
using	VectorDi			=	Vector<Dim, int>;					\
using	MatrixDr			=	Matrix<Dim, real>;

using	uchar = unsigned char;
using	ushort = unsigned short;
using	uint = unsigned int;
using	llong = long long;
using	ullong = unsigned long long;

using	std::size_t;

template <typename Type> concept HasZero = requires { Type::Zero(); };
template <typename Type> concept HasSquaredNorm = requires (Type obj) { obj.squaredNorm(); };

template <typename Type> inline constexpr Type Zero() { return Type(0); }
template <HasZero Type> inline Type Zero() { return Type::Zero(); }

} // namespaxe PhysX
