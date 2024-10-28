package test.java;

import static org.junit.jupiter.api.Assertions.assertEquals;

import main.java.Calculator;
import org.junit.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.MethodSource;

public class CalculatorTest {

    @Test
    public void testAdd() {
        assertEquals(5, Calculator.add(2, 3));
    }

    @ParameterizedTest
    @CsvSource({
            "3, 5, 2",
            "-3, -1, 2"
    })
    public void testSubtract(int expected, int a, int b) {
        assertEquals(expected, Calculator.subtract(a, b));
    }

    @ParameterizedTest
    @CsvSource({
            "10, 5, 2",
            "-2, -1, 2"
    })
    public void testMultiply(int expected, int a, int b) {
        assertEquals(expected, Calculator.multiply(a, b));
    }

    @ParameterizedTest
    @CsvSource({
            "2, 10, 5",
            "-2, -10, 5"
    })
    public void testDivide(int expected, int a, int b) {
        assertEquals(expected, Calculator.divide(a, b));
    }


    @ParameterizedTest(name = "{0} + {1} = {2}")
    @MethodSource("additionProvider")
    void testAddition(int a, int b, int sum) {
        assertEquals(sum, Calculator.add(a, b));
    }

    private static Object[][] additionProvider() {
        return new Object[][]{
                {0, 0, 0},
                {1, 1, 2},
                {1, 2, 3},
                {49, 51, 100}
        };
    }
}