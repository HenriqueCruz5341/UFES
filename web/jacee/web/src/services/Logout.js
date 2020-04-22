import { Component } from "react";

export default class Logout extends Component {
  componentDidMount() {
    localStorage.removeItem("LOGINJACEE_TOKEN");
    this.props.history.push("/");
    window.location.reload();
  }

  render() {
    return null;
  }
}
