// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Caml_exceptions = require("bs-platform/lib/js/caml_exceptions.js");

var MongoError = Caml_exceptions.create("Mongo-PublicbizApiV3.MongoError");

var $$Document = /* module */[];

var Cursor = /* module */[];

var Collection = /* module */[];

var Db = /* module */[];

var Client = /* module */[];

function connectAsync(t, url) {
  return new Promise((function (resolve, reject) {
                t.connect(url, (function (e, c) {
                        var exit = 0;
                        var val;
                        try {
                          val = e;
                          exit = 1;
                        }
                        catch (exn){
                          return reject([
                                      MongoError,
                                      e[/* message */0]
                                    ]);
                        }
                        if (exit === 1) {
                          return resolve(c);
                        }
                        
                      }));
                return /* () */0;
              }));
}

var MongoDb = /* module */[/* connectAsync */connectAsync];

exports.MongoError = MongoError;
exports.$$Document = $$Document;
exports.Cursor = Cursor;
exports.Collection = Collection;
exports.Db = Db;
exports.Client = Client;
exports.MongoDb = MongoDb;
/* No side effect */