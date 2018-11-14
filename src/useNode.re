let () =
  Node.Fs.readFileAsUtf8Sync("README.md")
  |> Js.String.split("\n")
  |> Array.iter(Js.log);

let decodeName = text =>
  Js.Json.parseExn(text) |> Json.Decode.(field("name", string));

let () =
  /* read [package.json] file */
  Node.Fs.readFileAsUtf8Sync("package.json") |> decodeName |> Js.log;