// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0

// ANTLR v4 grammar for the I++ DME protocol, derived from the formal syntax
// description in VDMA 8722:2024-04. This grammar is currently not able to parse
// XML data as part of a command or response, as no valid definition has been given
// by the standard. In addition, line terminators are treated as optional for
// practical reasons. However, they are required by the standard. There also seems
// to be a discrepancy between the formal syntax and the example data. The formal
// syntax does not allow a space after a #, whereas the examples contain one. This
// grammar currently does not allow spaces after a #. There is also a syntactic
// ambiguity between method and property_list as part of a response. 

grammar IPPDME;

line: command | response;

// Respones from server to client
response: (acknowledge_response | done_response | data_response | error_response) TERMINATOR?;
acknowledge_response: (tag | EVENT_TAG) ' &';
done_response: (tag | EVENT_TAG) ' %';
data_response: (tag | EVENT_TAG) ' #' data;
error_response: (tag | EVENT_TAG) ' ! Error' LEFT_PAR DIGIT COMMA four_digits COMMA STRING COMMA STRING RIGHT_PAR;

// Data send from server to client
data: numerical_data | property_data | method | property_list;
numerical_data: number (COMMA number)*;
property_data: STRING COMMA STRING;
property_list: property (COMMA property)*;

// Request from client to server
command: (tag | EVENT_TAG) ' ' method TERMINATOR?;
method: BASIC_NAME LEFT_PAR (method_argument_list | xml) RIGHT_PAR;
method_argument_list: (argument (COMMA argument)*)?;
argument: STRING | number | property | EVENT_TAG | BASIC_NAME;

property: name LEFT_PAR property_argument_list RIGHT_PAR;
property_argument_list: (number (COMMA number)*)?;

// Tags
tag: DIGIT four_digits; // Except 00000
EVENT_TAG: 'E' DIGIT DIGIT DIGIT DIGIT;

// Numbers and names
name: BASIC_NAME ('.' BASIC_NAME)*;
BASIC_NAME: LETTER (LETTER | DIGIT)*;
four_digits: DIGIT DIGIT DIGIT DIGIT;
number: ('+' | '-')? (DIGIT+ ('.' DIGIT*)? | '.' DIGIT+) exponent?; // Max. 16 characters
exponent: ('E' | 'e') ('+' | '-')? DIGIT (DIGIT (DIGIT)?)?;
xml: '@XMLDocumentString@@@'; // Invalid definition given by standard

// Fundamental non-terminals
STRING: '"' (' ' .. '!' | '#' .. '~')+ '"';
fragment LETTER: [a-zA-Z];
DIGIT: [0-9];
COMMA: (' ')* ',' (' ')*;
LEFT_PAR: (' ')* '(' (' ')*;
RIGHT_PAR: (' ')* ')';
TERMINATOR: '\r\n';
