#pragma once
#include <iostream>
#include <string>

class RunStateException : public std::exception {
  /******************************************************************************
   * public
   ******************************************************************************/
 public:
  // ErrorCode for the possible exceptions
  enum class ErrorCode {
    RequestFormatterEmptyRequest,
    RequestFormatterInvalidFormat,
    RequestFormatterInvalidId
  };

  /**
   * @brief Construct a new RunStateException object
   *
   * @param errorCode
   * @param appendMessage
   */
  RunStateException(
      const RunStateException::ErrorCode &errorCode,
      const std::string &appendMessage = "")
      : errorCode_(errorCode), appendMessage_(appendMessage) {}

  /**
   * @brief Returns error message
   * @return std::string
   */

  std::string message() {
    std::string message;
    switch (errorCode_) {
      case ErrorCode::RequestFormatterEmptyRequest:
        message = "RequestFormatterEmptyRequest string is empty";
        break;
      case ErrorCode::RequestFormatterInvalidFormat:
        message = "RequestFormatterInvalidFormat string format is invalid";
        break;
      case ErrorCode::RequestFormatterInvalidId:
        message = "RequestFormatterInvalidId is invalid";
      default:
        return "An unknown error occurred";
    }
    if (appendMessage_ != "") {
      message += ": ";
      message += appendMessage_;
    }
    return message;
  }

  /**
   * @brief Returns error code
   * @return ErrorCode
   */
  ErrorCode getErrorCode() { return errorCode_; }

  /******************************************************************************
   * private
   ******************************************************************************/
 private:
  /// errorCode_ error code
  const RunStateException::ErrorCode errorCode_;

  /// appendMessage_ error message
  std::string appendMessage_;
};