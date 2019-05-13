open Express;
open Mongo;

let app = express();
let mongoClient = MongoDb.client;
let mongoUrl = "mongodb://localhost:27017";

App.get(app, ~path="/") @@
Middleware.from((_, _, res) => {
  res
  |> Response.status(Response.StatusCode.Ok)
  |> Response.sendString("The PublicBizApi is working! ")
});

App.get(app, ~path="/mongodb") @@
PromiseMiddleware.from((_, _, res) => {
  MongoDb.connectAsync(mongoClient, mongoUrl)
  |> Js.Promise.then_(c => {
    let db = Client.db(c, "publicbiz");
    let collection = Db.collection(db, "templates");
    let d = Js.Dict.empty();
    let cursor = Collection.find(collection, d);
    Cursor.toArray(cursor, (_, docs) => Js.log2("Documents: ", docs));
    
    res
    |> Response.sendStatus(Response.StatusCode.Ok)
    |> Js.Promise.resolve
  })
})

let server = App.listen(app, ~port=9000, ~onListen= e => {
  switch e {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Server running at: http://localhost:9000"
  };
}, ());
