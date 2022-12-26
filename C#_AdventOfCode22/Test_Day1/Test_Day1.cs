using NUnit.Framework;
using Day1;

namespace Test_Day1
{
    public class Test_Day1
    {
        [Test]
        public void Multiply_PositiveInputs_ReturnsCorrectResult()
        {
            // Arrange
            var testable = new Testable();
            int lhs = 2;
            int rhs = 3;
            int expected = 6;

            // Act
            int result = testable.Multiply(lhs, rhs);

            // Assert
            Assert.AreEqual(expected, result);
        }

        [Test]
        public void Multiply_NegativeInputs_ReturnsCorrectResult()
        {
            // Arrange
            var testable = new Testable();
            int lhs = -2;
            int rhs = -3;
            int expected = 6;

            // Act
            int result = testable.Multiply(lhs, rhs);

            // Assert
            Assert.AreEqual(expected, result);
        }

        [Test]
        public void Multiply_ZeroInputs_ReturnsCorrectResult()
        {
            // Arrange
            var testable = new Testable();
            int lhs = 0;
            int rhs = 0;
            int expected = 0;

            // Act
            int result = testable.Multiply(lhs, rhs);

            // Assert
            Assert.AreEqual(expected, result);
        }

        [Test]
        public void Multiply_MixedInputs_ReturnsCorrectResult()
        {
            // Arrange
            var testable = new Testable();
            int lhs = -2;
            int rhs = 3;
            int expected = -6;

            // Act
            int result = testable.Multiply(lhs, rhs);

            // Assert
            Assert.AreEqual(expected, result);
        }
    }
}