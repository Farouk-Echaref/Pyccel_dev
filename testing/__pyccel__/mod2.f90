module mod2


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function matmul(a, b, c) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(in) :: a(0:,0:)
    real(f64), intent(in) :: b(0:,0:)
    real(f64), intent(inout) :: c(0:,0:)
    integer(i64) :: m
    integer(i64) :: p
    integer(i64) :: q
    integer(i64) :: n
    integer(i64) :: r
    integer(i64) :: s
    integer(i64) :: i
    integer(i64) :: j
    integer(i64) :: k

    m = size(a, 2_i64, i64)
    p = size(a, 1_i64, i64)
    q = size(b, 1_i64, i64)
    n = size(b, 2_i64, i64)
    r = size(c, 2_i64, i64)
    s = size(c, 1_i64, i64)
    if (p /= q .or. m /= r .or. n /= s) then
      Out_0001 = -1_i64
      return
    end if
    !$omp parallel
    !$omp do schedule(runtime)
    do i = 0_i64, m - 1_i64, 1_i64
      do j = 0_i64, n - 1_i64, 1_i64
        c(j, i) = 0.0_f64
        do k = 0_i64, p - 1_i64, 1_i64
          c(j, i) = c(j, i) + a(k, i) * b(k, j)
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel
    Out_0001 = 0_i64
    return

  end function matmul
  !........................................

end module mod2
