// Concrete Mathematics
// http://mathworld.wolfram.com/HarmonicNumber.html
//`$$H_n = \sum_{k=1}^n 1/k$$`
double H(int n)
{
    // Euler-Mascheroni Constant
    static const double gamma=0.577215664901532860606512090082402431042;
    // Hn = gamma + phi0(n + 1) // Digamma Function

    // Euler-Maclaurin Integration Formulas
    return gamma + log(n)
        + 1 / (2.0 * n)
        - 1 / (12.0 * n * n)
        + 1 / (120.0 * n * n * n * n)
        - 1 / (252.0 * n * n * n * n * n * n);
    // http://www.research.att.com/~njas/sequences/A006953
    // delta = epsilon / (240 * n ^ 8)
}
