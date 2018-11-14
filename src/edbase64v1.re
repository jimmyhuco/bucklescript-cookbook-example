[@bs.val] external btoa: string => string = "";

[@bs.val] external atob: string => string = "";

let () = {
  let text = "Hello World!";
  Js.log(text |> btoa);
  Js.log(text |> btoa |> atob);
};