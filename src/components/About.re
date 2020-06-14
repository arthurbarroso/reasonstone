[@react.component]
let make = () => {
  let aboutInfo = "Reasonstone is a simple project meant to help me learn ReasonML
  alongside reason-relay. This uses reason-relay with an external javascript utility 
  (which gets the window's scroll position) 
  to implement an infinite-scroll loader and display hearthstone
  cards fetched from a GraphQL server. This was made by Arthur Barroso.";

  let el = <a href="https://github.com/arthurbarroso">{ReasonReact.string("on github")}</a>;

  <Container>
    <Section child=el title="About" content=aboutInfo />
  </Container>
}