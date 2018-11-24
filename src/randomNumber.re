/* To make sure you have a different seed when your program runs each time */
let () = Random.init(Js.Date.now() |> int_of_float);

let () = Random.int(5) |> Js.log;