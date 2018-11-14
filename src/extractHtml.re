let input = {|
<html>
  <head>
    <title>A Simple HTML Document</title>
  </head>
  <body>
    <p>This is a very simple HTML document</p>
    <p>It only has two paragraphs</p>
  </body>
</html>
|};

let () =
  input
  |> Js.String.match([%re "/<p\\b[^>]*>(.*?)<\\/p>/gi"])
  |> (
    fun
    | Some(result) => result |> Js.Array.forEach(Js.log)
    | None => Js.log("no matches")
  );