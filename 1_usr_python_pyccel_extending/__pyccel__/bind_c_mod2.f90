module bind_c_mod2

  use mod2

  use, intrinsic :: ISO_C_Binding, only : c_ptr , C_F_Pointer , f64 => &
        C_DOUBLE , i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_matmul(bound_a, bound_a_shape_1, bound_a_shape_2, &
        bound_a_stride_1, bound_a_stride_2, bound_b, bound_b_shape_1, &
        bound_b_shape_2, bound_b_stride_1, bound_b_stride_2, bound_c, &
        bound_c_shape_1, bound_c_shape_2, bound_c_stride_1, &
        bound_c_stride_2) bind(c) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    type(c_ptr), value :: bound_a
    integer(i64), value :: bound_a_shape_1
    integer(i64), value :: bound_a_shape_2
    integer(i64), value :: bound_a_stride_1
    integer(i64), value :: bound_a_stride_2
    type(c_ptr), value :: bound_b
    integer(i64), value :: bound_b_shape_1
    integer(i64), value :: bound_b_shape_2
    integer(i64), value :: bound_b_stride_1
    integer(i64), value :: bound_b_stride_2
    type(c_ptr), value :: bound_c
    integer(i64), value :: bound_c_shape_1
    integer(i64), value :: bound_c_shape_2
    integer(i64), value :: bound_c_stride_1
    integer(i64), value :: bound_c_stride_2
    real(f64), pointer :: a(:,:)
    real(f64), pointer :: b(:,:)
    real(f64), pointer :: c(:,:)

    call C_F_Pointer(bound_a, a, [bound_a_shape_2 * bound_a_stride_2, &
          bound_a_shape_1 * bound_a_stride_1])
    call C_F_Pointer(bound_b, b, [bound_b_shape_1 * bound_b_stride_1, &
          bound_b_shape_2 * bound_b_stride_2])
    call C_F_Pointer(bound_c, c, [bound_c_shape_2 * bound_c_stride_2, &
          bound_c_shape_1 * bound_c_stride_1])
    Out_0001 = matmul(a = a(1_i64::bound_a_stride_2, 1_i64:: &
          bound_a_stride_1), b = b(1_i64::bound_b_stride_1, 1_i64:: &
          bound_b_stride_2), c = c(1_i64::bound_c_stride_2, 1_i64:: &
          bound_c_stride_1))

  end function bind_c_matmul
  !........................................

end module bind_c_mod2
