open Css;

let containerStyle =
  merge([
    style([
      background((hex("333")))  
    ]),
    "container"
  ]);


[@react.component]
let make = (~children: React.element) => 
  <div className=containerStyle>
    <Navbar />
    children
  </div>