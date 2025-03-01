// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0

// ANTLR v4 grammar for the I++ DME protocol, derived from the formal syntax
// description in VDMA 8722:2024-04. This grammar is currently not able to parse
// XML data as part of a command or response, as no valid definition has been given
// by the standard. In addition, line terminators are treated as optional for
// practical reasons. However, they are required in the standard.

grammar IPPDME;

line: command | response;

// Respones from server to client
response: (acknowledge_response | done_response | data_response | error_response) TERMINATOR?;
acknowledge_response: (tag | event_tag) ' &';
done_response: (tag | event_tag) ' %';
data_response: (tag | event_tag) ' #' data;
error_response: (tag | event_tag) ' ! Error' LEFT_PAR DIGIT COMMA four_digits COMMA STRING COMMA STRING RIGHT_PAR;

// Data send from server to client
data: numerical_data | property_data | method | property_list;
numerical_data: number (COMMA number)*;
property_data: STRING COMMA STRING;
property_list: property (COMMA property)*;

// Request from client to server
command: (tag | event_tag) ' ' method TERMINATOR?;
method: basic_name LEFT_PAR (method_argument_list | xml) RIGHT_PAR;
method_argument_list: (argument (COMMA argument)*)?;
argument: STRING | number | property | event_tag | basic_name;

property: name LEFT_PAR property_argument_list RIGHT_PAR;
property_argument_list: (number (COMMA number)*)?;

// Tags
tag: DIGIT four_digits; // Except 00000
event_tag: 'E' four_digits; // Except E0000
event_zero_tag: 'E0000';

// Numbers and names
name: basic_name ('.' basic_name)*;
basic_name: LETTER (LETTER | DIGIT)*;
four_digits: DIGIT DIGIT DIGIT DIGIT;
number: ('+' | '-')? (DIGIT+ ('.' DIGIT*)? | '.' DIGIT+) exponent?; // Max. 16 characters
exponent: ('E' | 'e') ('+' | '-')? DIGIT (DIGIT (DIGIT)?)?;
xml: '@XMLDocumentString@@@'; // Invalid definition given by standard

// Fundamental non-terminals
STRING: '"' (' ' .. '!' | '#' .. '~')+ '"';
LETTER: [a-zA-Z];
DIGIT: [0-9];
COMMA: (' ')* ',' (' ')*;
LEFT_PAR: (' ')* '(' (' ')*;
RIGHT_PAR: (' ')* ')';
TERMINATOR: '\n\r';
