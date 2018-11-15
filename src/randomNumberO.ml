(* To make sure you have a different seed when your program runs each time *)
let () = Js.Date.now () |> int_of_float |> Random.init

let () = Random.int 5 |> Js.log