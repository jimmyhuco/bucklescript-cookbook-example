open Webapi.Dom;

let printAllLinks = () =>
  document
  |> Document.querySelectorAll("a")
  |> NodeList.toArray
  |> Array.iter(n =>
       n
       |> Element.ofNode
       |> (
         fun
         | None => failwith("Not an Element")
         | Some(el) => Element.innerHTML(el)
       )
       |> Js.log
     );

let () = Window.setOnLoad(window, printAllLinks);