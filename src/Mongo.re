exception MongoError(string);

module Document {
  type t;
}

module Cursor {
  type t;
  type docs;
  type err;
  type callback = (err, docs) => unit;

  [@bs.send]
  external toArray: (t, callback) => unit = "";
}

module Collection {
  type t;
  type d = Js.Dict.t(unit);

  [@bs.send]
  external find: (t, d) => Cursor.t = "";
}

module Db {
  type t;
  type d;

  [@bs.send]
  external collection: (t, string) => Collection.t = "";
}

module Client {
  type t;

  [@bs.send]
  external db: (t, string) => Db.t = "";
}

module MongoDb {
  type t;
  type complete;
  type err = {
    message: string
  };

  type c = Client.t;

  type callback = (err, c) => unit;

  [@bs.send]
  external connect: (t, string, callback) => unit = "";

  [@bs.module "mongodb"]
  external client: t = "MongoClient";

  let connectAsync = (t, url) => {
    Js.Promise.make((~resolve, ~reject) => {
      connect(t, url, (e, c) => {
        switch e {
        | exception _ => reject(. MongoError(e.message))
        | _ => resolve(. c)
        };
      });
    })
  };
}
