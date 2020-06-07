open Css;

let containerStyle =
  merge([
    style([
      display(flexBox),
      paddingLeft(`percent(20.)),
      paddingRight(`percent(20.)),
      flexDirection(column),
      alignItems(center),
    ]),
    "container"
  ]);


[@react.component]
let make = (~children: React.element) =>
  <>
    <Navbar />
    <div className=containerStyle>
      children
    </div>
  </>