open Webapi.Base64;

let () = {
  let text = "Hello World!";
  Js.log(text |> btoa);
  Js.log(text |> btoa |> atob);
};