let person = [%obj {
                     name: {
                       first: "Bob",
                       last: "Zhmith",
                     },
                     age: 32,
                   }];

Js.log(person##name##first);