import sys
from PySide6.QtWidgets import QApplication
from PySide6.QtUiTools import QUiLoader
from PySide6.QtCore import QFile


class CalculatorApp:
    def __init__(self):
        # Load UI from file
        ui_file = QFile("calculator.ui")

        loader = QUiLoader()
        self.window = loader.load(ui_file)
        ui_file.close()

        self.current_value = ""
        self.stored_value = 0
        self.last_operation = None
        self.result_displayed = False
        self.waiting_for_operand = False


        # Connect number buttons
        for i in range(10):
            button = getattr(self.window, f"button_{i}")
            button.clicked.connect(lambda checked=False, digit=i: self.number_clicked(digit))


        # Connect operation buttons
        self.window.button_add.clicked.connect(lambda: self.operation_clicked("+"))
        self.window.button_subtract.clicked.connect(lambda: self.operation_clicked("-"))
        self.window.button_multiply.clicked.connect(lambda: self.operation_clicked("*"))
        self.window.button_divide.clicked.connect(lambda: self.operation_clicked("/"))

        # Connect equals button
        self.window.button_equals.clicked.connect(self.equals_clicked)

        # Connect clear button
        self.window.button_clear.clicked.connect(self.clear_clicked)

        # Connect comma button
        self.window.button_comma.clicked.connect(self.comma_clicked)

        # Initialize display
        self.update_display("0")

        # Show the window
        self.window.show()

    def number_clicked(self, digit):
        if self.result_displayed or self.waiting_for_operand:
            self.current_value = ""
            self.result_displayed = False
            self.waiting_for_operand = False

        self.current_value += str(digit)
        self.update_display(self.current_value)

    def comma_clicked(self):
        if self.result_displayed or self.waiting_for_operand:
            self.current_value = "0"
            self.result_displayed = False
            self.waiting_for_operand = False

        # Add comma only if not already present
        if "." not in self.current_value:
            # If current value is empty, add a leading zero
            if not self.current_value:
                self.current_value = "0"
            self.current_value += "."
            self.update_display(self.current_value)

    def operation_clicked(self, operation):
        # Special case: using subtract button to enter a negative number
        if operation == "-" and (not self.current_value or self.waiting_for_operand) and not self.result_displayed:
            self.current_value = "-"
            self.update_display(self.current_value)
            self.waiting_for_operand = False
            return

        # If there's a current value, process it
        if self.current_value:
            if self.last_operation:
                self.calculate()
            else:
                # First time an operation is clicked, store the value
                self.stored_value = float(self.current_value)
        elif self.result_displayed:
            # If no current value but we have a result, use the stored value
            pass
        else:
            # No current value and no result yet
            self.stored_value = 0

        # Set the operation for next calculation
        self.last_operation = operation
        self.waiting_for_operand = True
        self.result_displayed = False

    def equals_clicked(self):
        if self.last_operation:
            # If nothing entered after operator, use the stored value as both operands
            if not self.current_value and self.waiting_for_operand:
                self.current_value = str(self.stored_value)

            self.calculate()
            self.last_operation = None
            self.waiting_for_operand = False

    def calculate(self):
        if not self.current_value and not self.waiting_for_operand:
            return

        if not self.current_value and self.waiting_for_operand:
            # If no second operand was provided, use the first operand again
            current = self.stored_value
        else:
            current = float(self.current_value)

        if self.last_operation == "+":
            result = self.stored_value + current
        elif self.last_operation == "-":
            result = self.stored_value - current
        elif self.last_operation == "*":
            result = self.stored_value * current
        elif self.last_operation == "/":
            # Handle division by zero
            if current == 0:
                self.update_display("Error")
                self.reset_calculator()
                return
            result = self.stored_value / current
        else:
            result = current

        # Format result to avoid unnecessary decimal places
        if result == int(result):
            result_str = str(int(result))
        else:
            result_str = str(result)

        self.update_display(result_str)
        self.stored_value = result
        self.current_value = ""
        self.result_displayed = True

    def clear_clicked(self):
        self.reset_calculator()
        self.update_display("0")

    def reset_calculator(self):
        self.current_value = ""
        self.stored_value = 0
        self.last_operation = None
        self.result_displayed = False
        self.waiting_for_operand = False

    def update_display(self, text):
        self.window.label_display.setText(text)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    calculator = CalculatorApp()
    sys.exit(app.exec())
