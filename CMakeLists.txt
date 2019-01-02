cmake_minimum_required(VERSION 3.13)
project(project1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(project1 main.cpp Expression.h UnaryExpression.h Neg.cpp Neg.h BinaryExpression.h
        Div.cpp
        Div.h
        Expression.h
        Minus.cpp
        Minus.h
        Mul.cpp
        Mul.h
        Number.cpp
        Number.h
        Plus.cpp
        Plus.h FileHelper.cpp FileHelper.h
        ExpressionHelper.cpp ExpressionHelper.h Command.h ConnectCommand.cpp
        ConnectCommand.h MapsManagement.cpp MapsManagement.h BindCommand.cpp BindCommand.h ClientManagement.cpp
        ClientManagement.h EqualCommand.cpp EqualCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp
        SleepCommand.h BoolExpression.cpp BoolExpression.h ConditionCommand.cpp ConditionCommand.h IfCommand.cpp
        IfCommand.h WhileCommand.cpp WhileCommand.h
        VarExpression.cpp VarExpression.h
        DataReaderServer.cpp DataReaderServer.h OpenDataServerCommand.cpp OpenDataServerCommand.h
        Interpreter.cpp Interpreter.h VarCommand.cpp VarCommand.h)